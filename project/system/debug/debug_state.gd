extends State

func _process(_delta):
	if len(self.props) > 0:
		for prop in self.props:
			print(prop)
			print(prop.get())
		set_process(false)
