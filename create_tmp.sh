
#!/bin/bash

if [ $# -eq 0 ]; then
	echo "請提供一個輸入字串"
	exit 1
fi

input_str="$*"

number=$(echo "$input_str" | cut -d '.' -f 1)

if ! [[ "$number" =~ ^[0-9]+$ ]]; then
	echo "錯誤：輸入的第一部分應該是數字"
	exit 1
fi

formatted_number=$(printf "%04d" "$number")

string_part=$(echo "$input_str" | cut -d '.' -f 2- | sed 's/^ *//g')
formatted_string=$(echo "$string_part" | tr ' ' '_')

new_filename="${formatted_number}_${formatted_string}"
echo "$new_filename"

cp -r "0000_Template" "$new_filename"

cd "$new_filename" || exit
pwd
