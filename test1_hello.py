
class Employee:
    '所有员工的基类'
    empCount = 0

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1

    def displayCount(self):
        print
        "Total Employee %d" % self.empCount

    def displayEmployee(self):
        print
        "Name : ", self.name, ", Salary: ", self.salary

emp1 = Employee("Zara", 2000)
print(emp1.empCount)
print(emp1.name)
print(emp1.__doc__)
print(emp1.__module__)
print(emp1.__dict__)