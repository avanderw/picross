import avdw.picross.menu.Menu;
import openfl.display.Sprite;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Main extends Sprite
{
	var menu:Menu;

	public function new()
	{
		super();
		addChild(menu = new Menu());
		
		// Assets:
		// openfl.Assets.getBitmapData("img/assetname.jpg");
	}

}
