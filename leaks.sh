LEAKS=$(ps | grep "./cub3d" | grep -v "grep" | head -1 | awk {'print $1'})
while true; do leaks --list $LEAKS ; sleep 1 ; echo -n .; sleep 1 ; echo -n .; sleep 1 ; echo .; done;
