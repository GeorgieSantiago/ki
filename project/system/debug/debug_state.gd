extends State

func _process(_delta):
	print(self.props)
	if len(self.props) > 0:
		for prop in self.props:
			prop.connect("on_property_updated", handle_updated)
			print(prop.key())
			print(prop.value())
			if prop.key() == 'Button':
				prop.set_state("Jelly")
				print(prop.value())
		set_process(false)
		
func handle_updated(target):
	print(target.key())
	print(target.value())
	print("on_property_updated works")
