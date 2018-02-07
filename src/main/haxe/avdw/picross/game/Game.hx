package avdw.picross.game;

import avdw.create.grid.Grid;
import avdw.openfl.Util;
import format.SVG;
import openfl.Assets;
import openfl.events.Event;
import openfl.display.Sprite;
import openfl.events.MouseEvent;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Game extends Sprite
{
	var levelData:Dynamic;
	var svg:SVG;
	static public var colorSelector:ColorSelector;
	static public var brushing:Bool = false;

	public function new(levelData:Dynamic)
	{
		super();
		this.levelData = levelData;
		trace(levelData);

		svg = new SVG(Assets.getText("img/menu-button.svg")); // move to app_global area;

		addEventListener(Event.ADDED_TO_STAGE, setup);
		addEventListener(Event.ADDED_TO_STAGE, addListeners);
	}

	function addListeners(e:Event):Void
	{
		removeEventListener(Event.ADDED_TO_STAGE, addListeners);
		addEventListener(MouseEvent.MOUSE_DOWN, startBrushing);
		addEventListener(MouseEvent.MOUSE_UP, stopBrushing);
		addEventListener(Event.REMOVED_FROM_STAGE, removeListeners);
	}

	function removeListeners(e:Event):Void
	{
		removeEventListener(Event.REMOVED_FROM_STAGE, removeListeners);
		removeEventListener(MouseEvent.MOUSE_UP, stopBrushing);
		removeEventListener(MouseEvent.MOUSE_DOWN, startBrushing);
	}
	
	function startBrushing(e:MouseEvent):Void
	{
		brushing = true;
	}
	

	function stopBrushing(e:MouseEvent):Void
	{
		brushing = false;
	}

	function setup(e:Event):Void
	{
		var pctrWdth = levelData.width, pctrHght = levelData.height, clrCnt = 4, bttnDmntn = 3, errCnt = 1;
		var xTtl = pctrWdth + clrCnt + errCnt, xPxlWdth = stage.stageWidth / xTtl;
		var yTtl = pctrHght + clrCnt + errCnt + bttnDmntn, yPxlHght = stage.stageHeight / yTtl;
		var gridSize:Int = cast Math.min(xPxlWdth, yPxlHght);

		colorSelector = new ColorSelector(gridSize);
		colorSelector.x = 5 * gridSize;
		colorSelector.y = (yTtl - bttnDmntn) * gridSize;

		var bgGrid = Grid.create(yTtl,xTtl, gridSize);
		bgGrid.alpha = .3;
		addChild(bgGrid);

		var fgGrid = Grid.create( pctrHght,pctrWdth, gridSize, true);
		fgGrid.x += (clrCnt + errCnt) * gridSize;
		fgGrid.y += (clrCnt + errCnt) * gridSize;
		addChild(fgGrid);

		create(gridSize);

		var backBtn = Util.createBtn("back", 3 * gridSize, 1 * gridSize, svg);
		addChild(backBtn);

		backBtn.addEventListener(MouseEvent.CLICK, function (event)
		{
			trace("click,back");
			parent.addChild(Main.menu);
			parent.removeChild(this);
		});
	}

	function create(gridSize:Int):Void
	{
		var container = new Sprite();
		var bmd = Assets.getBitmapData(levelData.filename);
		for (y in 0...bmd.height)
		{
			for (x in 0...bmd.width)
			{
				colorSelector.putColor(bmd.getPixel(x, y));
				var block = new Block(gridSize);
				block.x = x * gridSize;
				block.y = y * gridSize;

				container.addChild(block);
			}
		}

		container.x = 5 * gridSize;
		container.y = 5 * gridSize;
		addChild(container);

		colorSelector.finalise();
		addChild(colorSelector);
	}

}