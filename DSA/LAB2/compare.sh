#!/bin/bash

output_file="aaa.txt"

hashing=("bad" "good")
prode=("linear" "double" "overflow")

for input_file_num in {2..4}; do
	for param1 in {1..2}; do
		for param2 in {0..2}; do
			input_file="${input_file_num}.in"
			message="${hashing[$param1 - 1]} hashing and ${prode[$param2]} prode with ${input_file}"
			echo $message

			# Run the program, measure time, and append the result to the output file
			echo $message >>$output_file # Append the message to the output file
			{ time (./main $param1 $param2 <$input_file >/dev/null); } 2>&1 | grep real >>$output_file
			echo "" >>$output_file # Add an empty line for better readability in the output file
		done
	done
done

echo "All executions completed."
