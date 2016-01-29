#! usr/bin/python

import json

from flask import *


app = Flask(__name__)

pieces = [] #tableau de pieces qu envoie le client mobile 

@app.route('/demandePiece', methods = ['GET']) #
def demande():

	#faire une boucle
	rep = make_response(json.dumps(pieces))
	rep.headers['Content-Type'] = 'application/json'
	return rep

@app.route('/recevoirPiece', methods = ['POST'])
def recevoirPiece():
	
	data = json.loads(request.data)
	pieces.append(data['value'])	
	rep = make_response(json.dumps(pieces))
	rep.headers['Content-Type'] = 'application/json'
	return rep


if __name__ == "__main__":
	app.run(host = '127.0.0.1', port = 5100, debug = True)






