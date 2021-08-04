# Project Euler Problem 24 Hackerrrank


factorials=[]
(0..13).each{
  |x|
  factorials << (x==0?  1: x *factorials[-1])
}

num = gets.chomp.to_i

def getFactRepr(num,len)
  ans = []
  i = 1
  while(i<=len)
    tmp = num / i
    ans << (num % i).to_s
    num = tmp
    i+=1
  end
  return ans.reverse
end

def getPerm(factArr, permElems)
  ans = ""
  factArr.each{
    |x|
    ans += permElems.delete_at(x.to_i)
  }
  return ans
end

digs = ('a'..'m').map{|x| x.to_s}
puts getPerm(getFactRepr(num-1,13),digs)
