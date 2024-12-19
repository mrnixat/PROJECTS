def encode(strs):
    if len(strs) == 0:
        return "empty"
    if strs == [""]:
            return "emtpy_string"
    full_string = ""
    for word in strs:
        if word == strs[-1]:
            full_string+=word
            return full_string
        full_string+=word + ";"
    return full_string
def decode(s):
    if s == "empty":
        return []
    if s == "emtpy_string":
        return [""]
    return s.split(";")

print (decode(encode(["hell", "world", "hello"])))

