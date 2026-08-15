class Person:
    yeu_nuoc = True
    khoe = 0
    
    def __init__(self, name, height, weight, is_tired):
        self.name = name
        self.height = height
        self.weight = weight
        self.is_tired = is_tired
        Person.khoe += (not is_tired)*1

    def status(self):
        if self.is_tired: print("di ngu thoi...")
        else: print("code tiep di pro :v")

    def check_body(self):
        if self.height < 150 and self.weight < 40: print("an uong them vao :v")
        else: print("tap gym di!")

class SocialAnxiety(Person):
    def is_society_fear_bro(self):
        if self.is_tired == True: print("nah bro")
        else: print("i guess yes")
