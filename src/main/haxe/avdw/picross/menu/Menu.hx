package avdw.picross.menu;

import avdw.create.grid.Grid;
import flash.events.Event;
import openfl.display.Graphics;
import openfl.display.Sprite;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Menu extends Sprite
{

	public function new()
	{
		super();
		
		//addChild(new Grid(11, 23, 10, true));
		addEventListener(Event.ADDED_TO_STAGE, start);
	}
	
	function start(e:Event):Void 
	{
		trace("john");

		var pctrWdth = 11, pctrHght = 23, clrCnt = 4, bttnDmntn = 3, errCnt = 1;
		var xTtl = pctrWdth + clrCnt + errCnt, xPxlWdth = stage.width / xTtl;
		var yTtl = pctrHght + clrCnt + errCnt + bttnDmntn, yPxlHght = stage.height / yTtl;

		var bgGrid = Grid.create(xTtl, yTtl, cast Math.min(xPxlWdth, yPxlHght));
		bgGrid.alpha = .3;
		addChild(bgGrid);
		
		var fgGrid = Grid.create(pctrWdth, pctrHght, cast Math.min(xPxlWdth, yPxlHght), true);
		fgGrid.x += (clrCnt + errCnt) * Math.min(xPxlWdth, yPxlHght);
		fgGrid.y += (clrCnt + errCnt) * Math.min(xPxlWdth, yPxlHght);
		addChild(fgGrid);
		
		addChild(new Grid(23, 11, 32, true));
	}
	
	

}