from person import SocialAnxiety
from person import Person

hieu = Person("Hieu", 170, 65, True)
nam = Person("Nam", 10,35, False)
hugn = Person("hung", 10,35, False)
hieu.status()
hieu.check_body()
print(hieu.is_tired == True)
if hieu.yeu_nuoc == True: print("Nice!")
print(Person.khoe)
phg = SocialAnxiety("phg", 175, 70, True)
phg.is_society_fear_bro()