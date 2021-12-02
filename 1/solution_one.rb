# 1521
increments = 0
last_depth = nil

File.readlines('input.txt').each do |line|
  depth = line.to_i

  if last_depth
    increments +=1 if depth > last_depth
  end

  last_depth = depth
end

puts increments
