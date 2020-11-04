
import tkinter as tk
import datetime

t0 = datetime.datetime.now()

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.clock = tk.Label(
            self.master, font=('Arial', 26), fg='Black')
        self.clock.pack()

        self.b = tk.Button(master, command=self.passTime, font=('Arial', 12))
        self.b.pack()
        self.b["text"] = "Go"

    def passTime(self):
        t1 = datetime.datetime.now()
        delta = t1 - t0
        delta = delta - datetime.timedelta(microseconds=delta.microseconds)
        self.clock['text'] = delta
        self.master.after(1000, self.passTime)

root = tk.Tk()
app = Application(root)
root.mainloop()