print("Enter the Number of levels: ")
levels = gets.strip.to_i

tree=[]
puts "\n\nPlease put the mentioned number of input. If the tree doesnt have a node at the place"
puts "Enter a * or something distinct\n\n"
levels.times do
  |x|
  print("Enter #{2**(x)} elements: ")
  a = gets.strip.split
  tree << a
end

tree = tree.flatten

def inorder(tree, i=0)
  if(tree[2*i + 1] != nil)
    inorder(tree, 2*i +1)
  end
  print(tree[i] + " ")
  if(tree[2*i+2]!=nil)
    inorder(tree,2*i+2)
  end
end

def preorder(tree, i=0)
  print(tree[i] + " ")
  if(tree[2*i + 1] != nil)
    preorder(tree, 2*i +1)
  end
  if(tree[2*i+2]!=nil)
    preorder(tree,2*i+2)
  end
end


def postorder(tree, i=0)
  if(tree[2*i + 1] != nil)
    postorder(tree, 2*i +1)
  end
  if(tree[2*i+2]!=nil)
    postorder(tree,2*i+2)
  end
  print(tree[i] + " ")
end

puts "Inorder:"
inorder(tree)
puts "\npreorder:"
preorder(tree)
puts "\npostorder:"
postorder(tree)
