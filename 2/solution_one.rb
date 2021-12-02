forward = 0
depth = 0

File.readlines('input.txt').each do |line|
  _, direction, magnitude = *line.match(/(\w+)\s+(\d+)/)

  case direction
  when "forward"
    forward += magnitude.to_i
  when "down"
    depth += magnitude.to_i
  when "up"
    depth -= magnitude.to_i
  end
end

puts "forward: #{forward}"
puts "depth: #{depth}"
puts "result: #{forward * depth}"