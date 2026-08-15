from person import Person

hieu = Person("Hieu", 170, 65, is_tired=True)
hieu.status()
hieu.check_body()
print(hieu.is_tired == True)