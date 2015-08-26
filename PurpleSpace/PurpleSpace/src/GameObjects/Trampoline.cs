using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace PurpleSpace.src.GameObjects
{
    class Trampoline : GameObject
    {
        GraphicsDeviceManager graphics;

        private Vector2 previousMousePosition;
        private bool isRun = false;
        private Vector2 confinesRun;
        public int sizeForFireman = 50;

        public Trampoline(GraphicsDeviceManager graphics)
            : base() 
        {
            this.graphics = graphics;
            position = new Vector2(Game1.gameCoordinates.X / 2, Game1.gameCoordinates.X - 35);
            confinesRun = new Vector2(0 + 50, Game1.gameCoordinates.X - 50);
        }

        override public void Update()
        {
            if (previousMousePosition.X != Mouse.GetState().X && previousMousePosition.X > confinesRun.X && previousMousePosition.X < confinesRun.Y)
            {
                this.position.X = Mouse.GetState().X; 
                isRun = true;
                animations[0].Play(position);
            }
            else
            {
                isRun = false;
                animations[0].Stop();
            }

            previousMousePosition = new Vector2(Mouse.GetState().X, Mouse.GetState().Y);
        }

        override public void Draw(SpriteBatch spriteBatch)
        {
            if (isRun) { animations[0].Draw(spriteBatch); }
            else
            {
                Vector2 origin = new Vector2((textures[0]).Width / 2, (textures[0]).Height/2);
                Rectangle sourceRectangle = new Rectangle(0, 0, (textures[0]).Width, (textures[0]).Height);
                spriteBatch.Draw(textures[0], new Vector2(position.X * Game1.moveScale.X + (Game1.screenSize.X - Game1.gameCoordinates.X * Game1.moveScale.X) / 2, position.Y * Game1.moveScale.Y), sourceRectangle, Color.White, 0.0f, origin, Game1.scale, SpriteEffects.None, 0.0f);
            }
        }
    }
}
