void buildConanProfile(String compiler)
{
	def compilerOptions = 
	[
		vs2022: 'compiler=msvc\n' +
			    'compiler.cppstd=20\n' +
			    'compiler.runtime=dynamic\n' +
			    'compiler.version=194'
	]
	
	def profileContent = '[settings]\n' +
						 'os=Windows\n' +
						 compilerOptions[compiler]

	writeFile file: 'profile', text: profileContent.toString()
}

return this