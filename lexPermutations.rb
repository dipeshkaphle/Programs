num =  gets.chomp

def getK(str)
  prev = str[0]
  index = nil
  str[1..].chars.each_with_index{
    |val,i|
    n=val
    if(prev < n)
      index = i
    end
    prev = val
  }
  return index
end

def getL(str,k)
  l=k+1
  str[k+2..].chars.each_with_index do
    |x,i|
    if(str[k]<x)
      l=i+k+2
    end
  end
  return l
end

def swap(str,k,l)
  str[k],str[l] = str[l],str[k]
end

def revSeqAfter(str,k)
  return str[..k]+str[k+1..].reverse
end

while(true)
  puts num
  k = getK(num)
  if(k==nil)
    break
  end
  l  = getL(num,k)
  swap(num,k,l)
  num = revSeqAfter(num,k)
end

