using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;

namespace PurpleSpace.src.GameObjects
{
    class BackGround : GameObject
    {
        public override void Update() {}

        public override void Draw(SpriteBatch spriteBatch)
        {
            Vector2 origin = new Vector2((textures[0]).Width / 2, (textures[0]).Height);
            Rectangle sourceRectangle = new Rectangle(0, 0, (textures[0]).Width, (textures[0]).Height);
            spriteBatch.Draw(textures[0], new Vector2(position.X * Game1.moveScale.X + (Game1.screenSize.X - Game1.gameCoordinates.X * Game1.moveScale.X) / 2, position.Y * Game1.moveScale.Y), sourceRectangle, Color.White, 0.0f, origin, Game1.scale, SpriteEffects.None, 0.0f);
        }
    }
}
