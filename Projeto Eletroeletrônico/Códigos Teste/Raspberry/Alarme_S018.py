import tkinter as tk #lib que já vem com o python

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.grid()
        self.create_widgets()
        self.peep = 0
        self.freq = 0


    def create_widgets(self):

        self.label1 = tk.Label(self)
        self.label1["text"] = "PEEP"
        self.label1.grid(row=0)

        self.label2 = tk.Label(self)
        self.label2["text"] = "Frequency"
        self.label2.grid(row=1)

        self.entry1 = tk.Entry(self)
        self.entry1.grid(row=0, column = 1)

        self.entry2 = tk.Entry(self)
        self.entry2.grid(row=1, column = 1)

        self.confirm = tk.Button(self)
        self.confirm["text"] = "Confirm"
        self.confirm["command"] = self.say_hi
        self.confirm.grid(row=2, column = 1)

    def say_hi(self):

        newWindow = tk.Toplevel(self.master)

        self.peep = self.entry1.get() #salva os valores nas variáveis
        self.freq = self.entry2.get()

        label0 = tk.Label(newWindow, text = "Is the data correct?")
        label1 = tk.Label(newWindow, text = "PEEP: " + self.peep )
        label2 = tk.Label(newWindow, text = "Frequency: " + self.freq)
        
        b_confirm = tk.Button(newWindow, text = "Confirm", command = self.master.destroy)
        b_cancel = tk.Button(newWindow, text = "Cancel", command = newWindow.destroy)

        label0.grid(row=0, column = 1)
        label1.grid(row=1, column = 0)
        label2.grid(row=2, column = 0)
        b_confirm.grid(row=3, column = 2)
        b_cancel.grid(row=3, column = 1)


root = tk.Tk(className="App")
app = Application(master=root)
app.mainloop()

#Confirmação que os valores estão sendo salvos nas variáveis
print("PEEP: " + app.peep + "\nFrequency: " + app.freq)
