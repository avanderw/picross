package avdw.picross.menu;

import avdw.create.grid.Grid;
import avdw.openfl.Util;
import avdw.picross.game.Game;
import format.SVG;
import haxe.Json;
import haxe.ds.StringMap;
import openfl.Assets;
import openfl.events.Event;
import openfl.display.Sprite;
import openfl.events.MouseEvent;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Menu extends Sprite
{
	var menuBtns:Array<Sprite> = new Array();
	var menuHistory:Array<String> = new Array();
	var menuIdx:String;
	
	var directoryMap:Map<String, Dynamic> = new StringMap();
	var levelMap:Map<String, Dynamic> = new StringMap();

	var gridSize:Int;
	var svg:SVG;
	var backBtn:Sprite;

	public function new()
	{
		super();
		
		var directoryData = Json.parse(Assets.getText("json/level.json"));
		mapDirectory(directoryData);
		
		menuIdx = Util.md5(directoryData);
		
		svg = new SVG(Assets.getText("img/menu-button.svg"));
		addEventListener(Event.ADDED_TO_STAGE, start);
	}

	function mapDirectory(dir:Dynamic):Void
	{
		directoryMap.set(Util.md5(dir), dir);
		for (i in 0...dir.directories.length)
		{
			mapDirectory(dir.directories[i]);
		}
		
		for (i in 0...dir.levels.length) {
			levelMap.set(Util.md5(dir.levels[i]), dir.levels[i]);
		}
	}

	function start(e:Event):Void
	{	
		var xTtl = 5, xPxlWdth = stage.stageWidth / xTtl;
		var yTtl = 11, yPxlHght = stage.stageHeight / yTtl;
		gridSize = cast Math.min(xPxlWdth, yPxlHght);

		var bgGrid = Grid.create(yTtl,xTtl, gridSize);
		bgGrid.alpha = .3;
		addChild(bgGrid);

		backBtn = Util.createBtn("back",  3 * gridSize, 1 * gridSize, svg);
		addChild(backBtn);

		backBtn.addEventListener(MouseEvent.CLICK, function (event)
		{
			trace("click,back");
			menuIdx = menuHistory.pop();
			
			destroyMenu();
			buildMenu();
		});

		buildMenu();
		removeEventListener(Event.ADDED_TO_STAGE, start);
	}

	function buildMenu():Void
	{
		trace("building", menuIdx);
		
		for (i in 0...directoryMap[menuIdx].directories.length)
		{
			var directoryBtn = Util.createBtn(directoryMap[menuIdx].directories[i].name,  3 * gridSize, 1 * gridSize, svg);
			directoryBtn.name = Util.md5(directoryMap[menuIdx].directories[i]);
			addChild(directoryBtn);

			directoryBtn.x = 1 * gridSize;
			directoryBtn.y = i * gridSize;

			directoryBtn.addEventListener(MouseEvent.CLICK, directoryClick);
			menuBtns.push(directoryBtn);
		}
		
		for (i in 0...directoryMap[menuIdx].levels.length) {
			var levelBtn = Util.createBtn(directoryMap[menuIdx].levels[i].filename,  3 * gridSize, 1 * gridSize, svg);
			levelBtn.name = Util.md5(directoryMap[menuIdx].levels[i]);
			addChild(levelBtn);
			
			levelBtn.x = 1 * gridSize;
			levelBtn.y = (i + directoryMap[menuIdx].directories.length) * gridSize;
			
			levelBtn.addEventListener(MouseEvent.CLICK, levelClick);
			menuBtns.push(levelBtn);
		}

		backBtn.x = 1 * gridSize;
		backBtn.y = (directoryMap[menuIdx].levels.length + directoryMap[menuIdx].directories.length) * gridSize;
	}
	
	function levelClick(e:MouseEvent):Void 
	{
		var key:String = cast (e.currentTarget, Sprite).name;
		trace("click", key);
		
		var game = new Game(levelMap[key]);
		parent.addChild(game);
		parent.removeChild(this);
	}

	function directoryClick(e:MouseEvent):Void
	{
		var key:String = cast (e.currentTarget, Sprite).name;
		trace("click", key);
		menuHistory.push(menuIdx);
		menuIdx = key;
	
		destroyMenu();
		buildMenu();
	}

	function destroyMenu()
	{
		var btn = menuBtns.pop();
		while (btn != null)
		{
			btn.removeEventListener(MouseEvent.CLICK, directoryClick);
			removeChild(btn);
			btn = menuBtns.pop();
		}

	}

}