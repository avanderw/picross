package avdw.picross.game;
import openfl.display.Sprite;
import openfl.events.MouseEvent;
import openfl.events.Event;

class Block extends Sprite
{
	var xIdx:Int;
	var yIdx:Int;
	var size:Int;
	var painted:Bool = false;
	var game:Game;
	public var pixel:Int;
	public var color:Int;

	public function new(game:Game, pixel:Int, size:Int, xIdx:Int, yIdx:Int)
	{
		super();
		this.pixel = pixel;
		this.game = game;
		this.size = size;
		this.xIdx = xIdx;
		this.yIdx = yIdx;

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
		if (game.brushing)
		{
			paint();
		}
	}

	function paint():Void
	{
		var erasing:Bool = game.colorManager.selected == ColorManager.ERASER;
		if (!painted || erasing)
		{
			graphics.clear();
			graphics.beginFill(game.colorManager.selected, erasing ? 0 : 1);
			graphics.drawRect(0, 0, size, size);
			graphics.endFill();
			painted = !erasing;
			color = game.colorManager.selected;
			game.hintContainer.refresh(xIdx, yIdx);
		}
	}
}