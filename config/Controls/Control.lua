-- Луашная таблица с функциями для управления персонажем в InputControl

function(actorRef)

InputControl = {
	Control = {
		W = function (actor) actor:setPosition(1, 1) end,
		A = nil,
		S = nil,
		D = nil
	}
}