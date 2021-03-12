def coalesce(str)
  unicodearr = ["\u2070", "\u00B9", "\u00B2", "\u00B3", "\u2074", "\u2075", "\u2076", "\u2077", "\u2078", "\u2079"]
  arr = (0..9).to_a
  unicodemap = arr.zip(unicodearr).to_h
  dict = {}
  dict.default = 0
  str.each_char { |c| dict[c] += 1 }
  dict.map { |k, v| k.to_s + v.to_s.each_char.map { |x| unicodemap[x.to_i] }.join }.join('.')
end

def main
  eqn = []
  print 'Number of equations: '
  n = gets.chop.to_i
  n.times do
    x = gets.chop.split.join(',')
    eqn << x
  end
  eqn = eqn.filter { |x| x != '' }.map { |y| "{#{y}}" }.join('')
  ans = `echo #{eqn}`
  # eqn1 = gets.chop.split.join(',')
  # eqn2 = gets.chop.split.join(',')
  ans = ans.split(' ').map { |x| x.each_char.map { |x| x }.sort.join }.sort
  dict = {}
  dict.default = 0
  ans.each do |x|
    dict[x] += 1
  end
  puts dict.map { |x, y| y != 1 ? "#{y}.#{coalesce(x.to_s)}" : coalesce(x.to_s) }.join('+')
end

main
