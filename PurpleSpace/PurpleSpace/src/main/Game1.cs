#region Using Statements
using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Storage;
using Microsoft.Xna.Framework.GamerServices;
using PurpleSpace.src.Particles;
using PurpleSpace.src.GameObjects;
using PurpleSpace.src.animation;
using System.Diagnostics;

#endregion

namespace PurpleSpace
{
    public class Game1 : Game
    {
        public static Vector2 scale;// = new Vector2(0.7f, 0.7f); размер объектов
        public static Vector2 moveScale; // для преобразования из gameCoordinates в обычные
        public static float littleSide;
        public static Vector2 screenSize;
        public static Vector2 gameCoordinates = new Vector2(480,480);

        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        Stopwatch stopWatch;
        ScenesHolder scenesHolder;

        public Game1()
            : base()
        {
            graphics = new GraphicsDeviceManager(this);
            //Vector2 ScreenResolution = new Vector2(GraphicsDevice.PresentationParameters.BackBufferWidth, GraphicsDevice.PresentationParameters.BackBufferHeight);
            screenSize = new Vector2(1000,900); //HD+
            //screenSize = new Vector2(480,480);
            //screenSize = new Vector2(480, 700);
            //screenSize = new Vector2(1400, 900);
            graphics.PreferredBackBufferWidth = (int) screenSize.X;// 480; //ширина экрана 
            graphics.PreferredBackBufferHeight = (int) screenSize.Y; //его высота   

            if (screenSize.X > screenSize.Y) {  littleSide = screenSize.Y; } 
            else {  littleSide = screenSize.X; }
            moveScale = new Vector2(littleSide / gameCoordinates.X, screenSize.Y / gameCoordinates.Y);
            scale = new Vector2((float)(0.5f * littleSide / gameCoordinates.X), (float)(0.5f * littleSide / gameCoordinates.Y));
            //graphics.IsFullScreen = true; //включаем полноэкранный режим
            //graphics.PreferredBackBufferWidth = (int)ScreenResolution.X;// 1366;// 1600;
            //graphics.PreferredBackBufferHeight = (int)ScreenResolution.Y;// 768; // 900;


            //graphics.IsFullScreen = true; 

            Window.IsBorderless = true;
            graphics.ApplyChanges(); 

            graphics.PreferMultiSampling = false;
            
           // graphics.ToggleFullScreen();
            Content.RootDirectory = "Content";
        }

        protected override void Initialize()
        {
            stopWatch = new Stopwatch();
            stopWatch.Start();
            scenesHolder = new ScenesHolder();
            base.Initialize();
        }

        protected override void LoadContent()
        {
            spriteBatch = new SpriteBatch(GraphicsDevice);
            scenesHolder.LoadContentAndCreateScenes(graphics,Content);
        }

        protected override void UnloadContent()
        {

        }

        protected override void Update(GameTime gameTime)
        {

            if (stopWatch.Elapsed.Milliseconds >= 1000 / 100)
            {
                scenesHolder.Update();
                stopWatch.Restart();
            }


            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Black); //.Clear(Color.CornflowerBlue);
            spriteBatch.Begin(SpriteSortMode.Deferred, BlendState.NonPremultiplied, SamplerState.PointClamp, DepthStencilState.Default, RasterizerState.CullNone);

            scenesHolder.Draw(spriteBatch);

            spriteBatch.End();
            base.Draw(gameTime);
        }
    }
}
