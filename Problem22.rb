names_list = File.open('Problem 22-names.txt', 'rb').read.split(',');
names = names_list.map { |x| x.tr("\"", "") }.sort
ranking_summation = names.each_with_index.collect do |name, index|
  name.each_char.map { |x| x.ord - 64 }.inject(:+) * (index + 1)#ranking of one word
end.inject(:+)
puts ranking_summation
