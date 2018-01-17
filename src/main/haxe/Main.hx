import avdw.picross.menu.Menu;
import openfl.display.Sprite;
import openfl.Lib;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Main extends Sprite 
{

	public function new() 
	{
		super();
		addChild(new Menu());
		// Assets:
		// openfl.Assets.getBitmapData("img/assetname.jpg");
	}

}
