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

	public function new(levelData:Dynamic)
	{
		super();
		this.levelData = levelData;

		trace(levelData);
		
		svg = new SVG(Assets.getText("img/menu-button.svg")); // move to app_global area;
		addEventListener(Event.ADDED_TO_STAGE, start);
	}

	function start(e:Event):Void
	{
		trace("start");
		var pctrWdth = 11, pctrHght = 23, clrCnt = 4, bttnDmntn = 3, errCnt = 1;
		var xTtl = pctrWdth + clrCnt + errCnt, xPxlWdth = stage.stageWidth / xTtl;
		var yTtl = pctrHght + clrCnt + errCnt + bttnDmntn, yPxlHght = stage.stageHeight / yTtl;
		var gridSize:Int = cast Math.min(xPxlWdth, yPxlHght);

		trace(xTtl, yTtl);
		create(gridSize);

		var bgGrid = Grid.create(yTtl,xTtl, gridSize);
		bgGrid.alpha = .3;
		addChild(bgGrid);

		var fgGrid = Grid.create( pctrHght,pctrWdth, gridSize, true);
		fgGrid.x += (clrCnt + errCnt) * gridSize;
		fgGrid.y += (clrCnt + errCnt) * gridSize;
		addChild(fgGrid);

		var backBtn = Util.createBtn("back", 3 * gridSize, 1 * gridSize, svg);
		addChild(backBtn);

		backBtn.addEventListener(MouseEvent.CLICK, function (event)
		{
			trace("click,back");
			parent.addChild(Main.menu);
			parent.removeChild(this);
		});
	}
	
	function create(gridSize:Int):Void {
		var container = new Sprite();
		var bmd = Assets.getBitmapData(levelData.filename);
		for (y in 0...bmd.height) {
			for (x in 0...bmd.width) {
				var sprite = new Sprite();
				sprite.graphics.beginFill(bmd.getPixel(x, y));
				sprite.graphics.drawRect(0, 0, gridSize, gridSize);
				sprite.graphics.endFill();
				sprite.x = x * gridSize;
				sprite.y = y * gridSize;
				container.addChild(sprite);
			}
		}
		
		container.x = 5 * gridSize;
		container.y = 5 * gridSize;
		addChild(container);
	}

}