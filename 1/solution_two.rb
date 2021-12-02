# 1543

increments = 0
last_window_sum = nil

window =   []

File.readlines('input.txt').each do |line|
  depth = line.to_i

  window << depth

  window.shift window.count > 3

  if window.count > 3
    window.shift
    window_sum = window.sum

    if last_window_sum
      increments += 1 if window_sum > last_window_sum
    end

    last_window_sum = window_sum
  end
end

puts increments
