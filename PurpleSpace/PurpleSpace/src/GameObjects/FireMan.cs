using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using PurpleSpace.src.animation;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input;

namespace PurpleSpace.src.GameObjects
{
    class FireMan : GameObject
    {
        GraphicsDeviceManager graphics;

        private Vector2 prePosition;
        private Vector2 dPosition;
        private Vector4 confinesFly;
        private Vector2 previousMousePosition;
        private bool currentSideRight = true;
        private bool inAttack = false;
        private float gravity  = 0.2f;
        private float kickOfWater = 0.2f;
        private const int cofines = 230;
        public bool onBase = true;
        public Trampoline trampoline { set; get; }
        

        /*
        public FireMan(Texture2D texture) : base(texture)
        {
            prePosition = new Vector2(200,200);
            dPosition = new Vector2();
            position = new Vector2(201,201);
        } */
        /*
position = new Vector2(Mouse.GetState().X, Mouse.GetState().Y);
if (animations.Count >= 1) animations[0].Play(position);
 */

        public FireMan(GraphicsDeviceManager graphics)
            : base() 
        {
            this.graphics = graphics;
            prePosition = new Vector2(Game1.gameCoordinates.X / 2, Game1.gameCoordinates.Y / 2 - 6);
            dPosition = new Vector2();
            position = new Vector2(Game1.gameCoordinates.X / 2, Game1.gameCoordinates.Y / 2 );
            confinesFly = new Vector4(Game1.gameCoordinates.X / 2 - cofines, //+ (Game1.screenSize.X - Game1.gameCoordinates.X)/ 2.5f /Game1.moveScale.X , 
                                      Game1.gameCoordinates.Y / 2 - cofines,
                                      Game1.gameCoordinates.X / 2 + cofines,// - (Game1.screenSize.X - Game1.gameCoordinates.X) / 2.5f / Game1.moveScale.X, 
                                      Game1.gameCoordinates.Y / 2 + cofines-20);
        }

        override public void Update()
        {
            if (onBase) 
            {
                position = new Vector2(trampoline.position.X, trampoline.position.Y-14); 
                if (Mouse.GetState().LeftButton == ButtonState.Pressed)
                { onBase = false; prePosition.X = position.X; prePosition.Y = position.Y - 11; } 
            }
            else
            {
                particleControllers[0].Update();

                //currentTextureSize = new Vector2(0,0);
                //currentTextureSize = animations[0].getTextureSize();


                dPosition = new Vector2(position.X - prePosition.X, position.Y - prePosition.Y);
                prePosition = new Vector2(position.X, position.Y);
                position = new Vector2(position.X + dPosition.X, position.Y + dPosition.Y + gravity);

                if (position.X  >= confinesFly.Z || position.X  <= confinesFly.X)
                {
                    float buffer;
                    buffer = position.X;
                    position.X = prePosition.X;
                    prePosition.X = buffer;
                }

                if (position.Y >= confinesFly.W || position.Y <= confinesFly.Y)
                {
                    if (position.X > trampoline.position.X + trampoline.sizeForFireman || position.X < trampoline.position.X - trampoline.sizeForFireman) { confinesFly.W = 200000; }
                    else
                    {
                        position.X+=(position.X-trampoline.position.X)/10;
                    }
                }

                if (position.Y   >= confinesFly.W || position.Y   <= confinesFly.Y)
                {
                    float buffer;
                    buffer = position.Y;
                    position.Y = prePosition.Y;
                    prePosition.Y = buffer;

                }
                //if (position.Y  >= confinesFly.W) { prePosition.Y = position.Y; }


                if (previousMousePosition.X < Mouse.GetState().X) { currentSideRight = true; }
                else
                {
                    if (previousMousePosition.X > Mouse.GetState().X) { currentSideRight = false; }
                }
                previousMousePosition = new Vector2(Mouse.GetState().X, Mouse.GetState().Y);


                if (Mouse.GetState().LeftButton == ButtonState.Pressed) { inAttack = true; }
                else { inAttack = false; }


                if (inAttack)
                {

                    if (Math.Abs(prePosition.X - position.X) <= 0.1f) { if (prePosition.X > position.X) position.X -= 0.2f; else { position.X += 0.2f; } }
                    else
                        if (currentSideRight)
                        {
                            if (position.X - currentTextureSize.X / 2 > confinesFly.X) position.X -= kickOfWater / Math.Abs(prePosition.X - position.X);
                        }
                        else
                        {
                            if (position.X + currentTextureSize.X / 2 < confinesFly.Z) position.X += kickOfWater / Math.Abs(prePosition.X - position.X);
                        }

                    particleControllers[0].generateParticles(new Vector2(position.X + (currentSideRight ? +20 : -20), position.Y),
                                                         currentSideRight, dPosition);
                    //particleControllers[0].generateParticles(new Vector2(position.X + (currentSideRight ? +20 : -20), position.Y-15),
                     //                currentSideRight, dPosition);
                }
            }

            if (currentSideRight) { animations[1].Stop(); animations[0].Play(position); }
            else { animations[0].Stop(); animations[1].Play(position); }
        }

        override public void Draw(SpriteBatch spriteBatch)
        {
            if (inAttack)
            {
                if (currentSideRight)
                {
                    Vector2 origin = new Vector2((textures[0]).Width / 2, (textures[0]).Height / 2);
                    Rectangle sourceRectangle = new Rectangle(0, 0, (textures[0]).Width, (textures[0]).Height);
                    spriteBatch.Draw(textures[0], new Vector2(position.X * Game1.moveScale.X + (Game1.screenSize.X - Game1.gameCoordinates.X * Game1.moveScale.X) / 2, position.Y * Game1.moveScale.Y), sourceRectangle, Color.White, 0.0f, origin, Game1.scale, SpriteEffects.None, 0.0f);
                }
                else
                {
                    Vector2 origin = new Vector2((textures[0]).Width / 2, (textures[0]).Height / 2);
                    Rectangle sourceRectangle = new Rectangle(0, 0, (textures[0]).Width, (textures[0]).Height);
                    spriteBatch.Draw(textures[1], new Vector2(position.X * Game1.moveScale.X + (Game1.screenSize.X - Game1.gameCoordinates.X * Game1.moveScale.X) / 2, position.Y * Game1.moveScale.Y), sourceRectangle, Color.White, 0.0f, origin, Game1.scale, SpriteEffects.None, 0.0f);
                }
            }
            else
            {
                foreach (Animation a in animations)
                {
                    a.Draw(spriteBatch);
                }
            }

            particleControllers[0].Draw(spriteBatch);
            /*
            else
            {
                Vector2 origin = new Vector2((textures[0]).Width / 2, ( textures[0]).Height / 2);
                Rectangle sourceRectangle = new Rectangle(0, 0, (textures[0]).Width, (textures[0]).Height);
                spriteBatch.Draw(textures[0], position, sourceRectangle, Color.White, 0.0f, origin, 1f, SpriteEffects.None, 0.0f);   
            }
             * */
        }
    }
}

