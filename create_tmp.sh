#! /bin/bash

if [ -z "$1" ]; then
	  echo "請提供一個輸入字串"
	    exit 1
fi

input_str="$1"
number=$(echo "$input_str" | cut -d '.' -f 1)
formatted_number=$(printf "%04d" "$number")

string_part=$(echo "$input_str" | cut -d '.' -f 2-)
formatted_string=$(echo "$string_part" | tr ' ' '_')

new_filename="${formatted_number}${formatted_string}"
echo $new_filename

cp -r "0000_Template" "$new_filename"

