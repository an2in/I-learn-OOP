class Person:
    def __init__(self, name, height, weight, is_tired=False):
        self.name = name
        self.height = height
        self.weight = weight
        self.is_tired = is_tired

    def status(self):
        if self.is_tired: print("di ngu thoi...")
        else: print("code tiep di pro :v")

    def check_body(self):
        if self.height < 150 and self.weight < 40: print("an uong them vao :v")
        else: print("tap gym di!")
