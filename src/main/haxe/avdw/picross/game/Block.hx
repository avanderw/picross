package avdw.picross.game;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.events.Event;

class Block extends Sprite
{
	var size:Int;
	
	public function new(size:Int)
	{
		super();
		this.size = size;

		graphics.beginFill(0, 0);
		graphics.drawRect(0, 0, size, size);
		graphics.endFill();
		
		addEventListener(Event.ADDED_TO_STAGE, addListeners);
	}

	function addListeners(e:Event):Void
	{
		removeEventListener(Event.ADDED_TO_STAGE, addListeners);
		
		addEventListener(MouseEvent.MOUSE_OVER, paintWhenBrushing);
		addEventListener(MouseEvent.MOUSE_DOWN, paintOnMouseDown);
		addEventListener(Event.REMOVED_FROM_STAGE, removeListeners);
	}

	function removeListeners(e:Event):Void
	{
		removeEventListener(Event.REMOVED_FROM_STAGE, removeListeners);
		removeEventListener(MouseEvent.MOUSE_DOWN, paintOnMouseDown);
		removeEventListener(MouseEvent.MOUSE_OVER, paintWhenBrushing);
	}


	function paintOnMouseDown(e:MouseEvent):Void
	{
		paint();
	}

	function paintWhenBrushing(e:MouseEvent):Void
	{
		if (Game.brushing)
		{
			paint();
		}
	}
	
	function paint():Void
	{
		graphics.clear();
		graphics.beginFill(Game.colorSelector.selected, Game.colorSelector.selected == ColorSelector.eraser ? 0 : 1);
		graphics.drawRect(0, 0, size, size);
		graphics.endFill();
	}
}