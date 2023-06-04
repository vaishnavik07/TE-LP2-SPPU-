# Problem Statements:	
# Implement any one Expert System: Hospital management system based on symptoms predict disease 

class Symptom:
    def __init__(self, question=None, positive_symptom=None, negative_symptom=None, diagnosis=None):
        self.question = question
        self.positive_symptom = positive_symptom
        self.negative_symptom = negative_symptom
        self.diagnosis = diagnosis

knowledge_base = {
    "fever": Symptom("Do you have a fever?", positive_symptom="sore_throat", negative_symptom="no_fever"),
    "sore_throat": Symptom("Do you have a sore throat?", positive_symptom="cough", negative_symptom="no_sore_throat"),
    "cough": Symptom("Do you have a cough?", positive_symptom="difficulty_breathing", negative_symptom="no_cough"),
    "difficulty_breathing": Symptom("Are you experiencing difficulty breathing?", positive_symptom="diagnosis1", negative_symptom="diagnosis2"),
    "diagnosis1": Symptom(diagnosis="You may have COVID-19. Please seek medical attention."),
    "diagnosis2": Symptom(diagnosis="You may have a common cold. Rest and take care of yourself."),
    "no_fever": Symptom(diagnosis="No fever detected."),
    "no_sore_throat": Symptom(diagnosis="No sore throat detected."),
    "no_cough": Symptom(diagnosis="No cough detected."),
    "no_difficulty_breathing": Symptom(diagnosis="No difficulty breathing detected.")
}

def run_expert_system():
    current_symptom = "fever"
    symptoms_stack = []
    
    while True:
        symptom = knowledge_base[current_symptom]
        
        if symptom.question:
            while True:
                answer = input(symptom.question + " (yes/no): ").lower()
                
                if answer == "yes":
                    symptoms_stack.append(current_symptom)
                    current_symptom = symptom.positive_symptom
                    break
                elif answer == "no":
                    current_symptom = symptom.negative_symptom
                    break
                else:
                    print("Invalid input. Please enter 'yes' or 'no'.")
        else:
            print(symptom.diagnosis)
            if symptoms_stack:
                while True:
                    backtracking = input("Do you want to go back and answer the previous question? (yes/no): ").lower()
                    if backtracking == "yes":
                        current_symptom = symptoms_stack.pop()
                        break
                    elif backtracking == "no":
                        break
                    else:
                        print("Invalid input. Please enter 'yes' or 'no'.")
            else:
                break
            
def add_patient():
    name=input("Enter name: ")
    age=input("Enter age: ")
    gender=input("Enter gender")
    patients.append({"name":name, "age":age,"gender":gender})
    print("Patient added successfully")
    
def display():
    if not patients:
        print("No patients")
        return
    cnt=1
    for patient in patients:
        print("patient"+str(cnt)+":")
        print("name"+ patient["name"])
        print("age"+ patient["age"])
        
def search_patient():
    nm=input("patient's name")
    # ag=input("patient's age")
    found=False
    for patient in patients:
        if(patient["name"]==nm):
            print("patient found")
            print("age"+ patient["age"])
            found=True
            break
    if found==False:
        print("Patient not found")
    
            
patients=[]

print("Welcome to Expert System!!!!")
while True:
    print("Please select one choice: ")
    print("\n1.add patient \n2.display \n3.search patient\n4.disease prediction\n5.quit")
    ch=input("enter your choice")
    if ch=='1':
        add_patient()
    elif ch=='2':
        display()
    elif ch=='3':
        search_patient()
    elif ch=='4':
        run_expert_system()
    else:
        print("bye")
        break
    

# add_patient()
# display()
# search_patient()
# run_expert_system()
