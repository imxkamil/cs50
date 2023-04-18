from flask import Flask, render_template, request

app = Flask(__name__) # __name__ - reffers to current file - turn this file into a flask application

@app.route("/", methods=["GET", "POST"])
def index():
    #name = requests.args.get("name", "world") # get allows me to pass as argument value which i want to get
                                    # second argument is for default value if no/wrong name provided
    #if "name" in request.args:
        #name = request.args["name"]
    #else:
        #name = "world"
    #return render_template("index.html", name=name) # first name is placeholder for the {{ placeholder_name }} in template
    if request.method == "GET":
        return render_template("index.html")
    elif request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
#@app.route("/greet", methods=["POST"])
#def greet():
#return render_template("greet.html", name=request.args.get("name", "world"))