#!/bin/bash
# find-lab-pcs.sh
# Scans the subnet, matches known MACs to current IPs,
# and auto-updates ~/.ssh/config so hostnames always resolve correctly.

SSH_CONFIG="$HOME/.ssh/config"
MARKER_START="# >>> lab-pcs-autogen >>>"
MARKER_END="# <<< lab-pcs-autogen <<<"
SSH_USER="admin"   # change to whatever admin username you use

declare -A KNOWN_MACS=(
    ["aa:bb:cc:dd:ee:01"]="pc01"
    ["aa:bb:cc:dd:ee:02"]="pc02"
    ["aa:bb:cc:dd:ee:03"]="pc03"
    # add all your known lab MACs here
)

echo "Scanning subnet..."
SCAN=$(sudo arp-scan --localnet | grep -Eo '([0-9]{1,3}\.){3}[0-9]{1,3}[[:space:]]+([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2}')

# Build the new config block in a temp file first
TMP_BLOCK=$(mktemp)
echo "$MARKER_START" >> "$TMP_BLOCK"

FOUND_COUNT=0
while read -r ip mac; do
    mac_lower=$(echo "$mac" | tr 'A-F' 'a-f')
    name="${KNOWN_MACS[$mac_lower]}"
    if [[ -n "$name" ]]; then
        {
            echo "Host $name"
            echo "    HostName $ip"
            echo "    User $SSH_USER"
            echo ""
        } >> "$TMP_BLOCK"
        echo "$name -> $ip"
        ((FOUND_COUNT++))
    fi
done <<< "$SCAN"

echo "$MARKER_END" >> "$TMP_BLOCK"

if [[ "$FOUND_COUNT" -eq 0 ]]; then
    echo "No known machines found on this scan. SSH config left untouched."
    rm "$TMP_BLOCK"
    exit 1
fi

# Ensure ~/.ssh/config exists
mkdir -p "$HOME/.ssh"
touch "$SSH_CONFIG"

# Remove old autogen block if present, then append the fresh one
if grep -q "$MARKER_START" "$SSH_CONFIG"; then
    sed -i "/$MARKER_START/,/$MARKER_END/d" "$SSH_CONFIG"
fi

cat "$TMP_BLOCK" >> "$SSH_CONFIG"
rm "$TMP_BLOCK"

chmod 600 "$SSH_CONFIG"
echo ""
echo "Updated $SSH_CONFIG with $FOUND_COUNT machine(s)."
echo "You can now run: ssh pc01, ssh pc02, etc."