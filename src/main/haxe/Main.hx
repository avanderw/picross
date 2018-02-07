import avdw.picross.menu.Menu;
import openfl.display.Sprite;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Main extends Sprite
{
	static public var menu:Menu;

	public function new()
	{
		super();
		addChild(menu = new Menu());
	}

}
