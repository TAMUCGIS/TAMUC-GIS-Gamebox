local Renderer = {}

local num_of_layers = 5
local insert = table.insert 
local remove = table.remove



function Renderer:create()
	local renderer = {}
	
	renderer.drawers = {}
	for i=0,num_of_layers do
		renderer.drawers[i] = {}
	end
	
	function renderer:addRenderer(obj,Layer)
		local l = layer or 0
		insert(self.drawers[l],obj)
		
	end
	
	function renderer:draw()
	
		for layer = 0,#self.drawers do
			for draw = 0,#self.drawers[layer] do
			local obj = self.drawer[layer][draw]
			obj:draw()
	
	end
	
	return renderer
end

return Renderer