import avdw.picross.menu.Menu;
import openfl.display.Sprite;

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
