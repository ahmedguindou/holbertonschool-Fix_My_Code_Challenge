###
#
#  Sort integer arguments (ascending) 
#
###

result = []

ARGV.each do |arg|
  # Skip if not an integer
  next if arg !~ /^-?\d+$/

  # Convert to integer and add to result
  result << arg.to_i
end

# Sort the array in ascending order
result.sort!

# Print the sorted result
puts result
