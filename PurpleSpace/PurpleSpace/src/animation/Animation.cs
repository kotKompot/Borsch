using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using System.Diagnostics;

namespace PurpleSpace.src.animation
{
    class Animation
    {
        Texture2D texture;
        Vector2 frameSize;
        int frameCount;
        int currentFrame = 0;
        int framePerSecond;
        Vector2 position;
        bool isActiveOneTurn = false;
        bool isActiveEternal = false;
        Stopwatch stopWatch;
        

        public Animation(Texture2D texture, Vector2 frameSize, int framePerSecond)
        {
            this.texture = texture;
            this.frameSize = frameSize;
            this.framePerSecond = framePerSecond;
            this.position = new Vector2(0,0);
            frameCount = (int)  Math.Round(texture.Width / frameSize.X);
            stopWatch = new Stopwatch();
            stopWatch.Start();
        }

        public void Play(Vector2 position)
        {
            this.position = position;
            isActiveEternal = true;
        }

        public void PlayOneTime(Vector2 position)
        {
            this.position = position;
            isActiveOneTurn = true;
        }

        public void Stop()
        {
            isActiveOneTurn = false;
            isActiveEternal = false;
        }

        public void Update()
        {

        }

        public Vector2 getTextureSize() {
            return frameSize;
        }

        public void Draw(SpriteBatch spriteBatch)
        {
            if (stopWatch.Elapsed.Milliseconds >= 1000 / framePerSecond)
            {
                ++currentFrame;
                stopWatch.Restart();
            }


            if (isActiveEternal)
            {
                if (currentFrame + 1 > frameCount) currentFrame = 0;

                Rectangle sourceRectangle =
                new Rectangle(currentFrame * (int)frameSize.X, 0, (int)frameSize.X, (int)frameSize.Y);

                Vector2 origin = new Vector2(sourceRectangle.Width / 2, sourceRectangle.Height / 2);
                spriteBatch.Draw(texture, new Vector2(position.X * Game1.moveScale.X + (Game1.screenSize.X - Game1.gameCoordinates.X * Game1.moveScale.X) / 2, position.Y * Game1.moveScale.Y), sourceRectangle, Color.White, 0, origin, Game1.scale, SpriteEffects.None, 0);
            }
        }
    }
}
