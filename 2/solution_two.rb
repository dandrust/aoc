forward = 0
depth = 0
aim = 0

File.readlines('input.txt').each do |line|
  _, directive, magnitude = *line.match(/(\w+)\s+(\d+)/)

  magnitude = magnitude.to_i

  case directive
  when "forward"
    forward += magnitude
    depth += (magnitude * aim)
  when "down"
    aim += magnitude.to_i
  when "up"
    aim -= magnitude.to_i
  end
end

puts "forward: #{forward}"
puts "depth: #{depth}"
puts "result: #{forward * depth}"