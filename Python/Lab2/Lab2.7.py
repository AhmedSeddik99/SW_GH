import re
# print(dir(re))

text = "Age:25 Name:Mohamed Ahmed position:Design"

j = re.search(r'Name\s*:\s*\w*\s\w*', text)
print(j)    
print(j.group())

