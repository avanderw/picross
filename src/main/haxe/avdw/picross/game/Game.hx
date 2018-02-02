package avdw.picross.game;

import avdw.create.grid.Grid;
import openfl.Assets;
import openfl.events.Event;
import openfl.display.Sprite;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Game extends Sprite
{
	var levelData:Dynamic;

	public function new(levelData:Dynamic)
	{
		super();
		this.levelData = levelData;
		
		trace(levelData);
		var bmd = Assets.getBitmapData(levelData.filename);
		trace(bmd.getPixel32(0, 0));
		
		addEventListener(Event.ADDED_TO_STAGE, start);
	}

	function start(e:Event):Void
	{
		var pctrWdth = 11, pctrHght = 23, clrCnt = 4, bttnDmntn = 3, errCnt = 1;
		var xTtl = pctrWdth + clrCnt + errCnt, xPxlWdth = stage.stageWidth / xTtl;
		var yTtl = pctrHght + clrCnt + errCnt + bttnDmntn, yPxlHght = stage.stageHeight / yTtl;

		var bgGrid = Grid.create(yTtl,xTtl, cast Math.min(xPxlWdth, yPxlHght));
		bgGrid.alpha = .3;
		addChild(bgGrid);

		var fgGrid = Grid.create( pctrHght,pctrWdth, cast Math.min(xPxlWdth, yPxlHght), true);
		fgGrid.x += (clrCnt + errCnt) * Math.min(xPxlWdth, yPxlHght);
		fgGrid.y += (clrCnt + errCnt) * Math.min(xPxlWdth, yPxlHght);
		addChild(fgGrid);

	}

}