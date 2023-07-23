extends State

var toggle = false

func _process(delta):
	if len(self.props) > 0 and toggle != true:
		toggle = true
		for prop in self.props:
			print(prop.get())
		
