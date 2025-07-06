
#!/bin/bash

if [ $# -eq 0 ]; then
	echo "please enter a string"
	return 0
fi

input_str="$*"

number=$(echo "$input_str" | cut -d '.' -f 1)

if ! [[ "$number" =~ ^[0-9]+$ ]]; then
echo "error : first part of the string must be a number"
	exit 1
fi

formatted_number=$(printf "%04d" "$number")

string_part=$(echo "$input_str" | cut -d '.' -f 2- | sed 's/^ *//g')
formatted_string=$(echo "$string_part" | tr ' ' '_')

new_filename="${formatted_number}_${formatted_string}"
echo "$new_filename"


if [ -d "$new_filename" ]; then
	echo "Directory $new_filename already exists"
else
	echo "Creating directory $new_filename"
	cp -r "0000_Template" "$new_filename"
fi

cd "$new_filename" || exit
pwd
