
puts "INDEX, WTF?"

n=1

File.readlines('input.txt').each do |line|
  directive, magnitude = *line.strip.split(" ")
  puts "    OMG #{n}"
  puts "        directive R \"#{directive}\""
  puts "        magnitude R \"#{magnitude}\""
  puts "        GTFO"
  n += 1
end

puts "OIC"