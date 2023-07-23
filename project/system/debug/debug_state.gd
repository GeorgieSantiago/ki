extends State

func _process(_delta):
	if len(self.props) > 0:
		for prop in self.props:
			print(prop.key())
			print(prop.value())
		set_process(false)
