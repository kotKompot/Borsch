using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Xna.Framework.Graphics;
using PurpleSpace.src.GameObjects;
using PurpleSpace.src.Particles;
using Microsoft.Xna.Framework;
using PurpleSpace.src.animation;
using PurpleSpace.src.main;
using Microsoft.Xna.Framework.Content;


namespace PurpleSpace
{
    class ScenesHolder
    {
        private List<Scene> scenes;
        public int currentSceneNumber { set; get; }

        public ScenesHolder()
        {
            scenes = new List<Scene>();
        }

        public void Update()
        {
            scenes[currentSceneNumber].Update();
        }

        public void Draw(SpriteBatch spriteBatch)
        {
            scenes[currentSceneNumber].Draw(spriteBatch);
        }

        public void AddScene(Scene scene)
        {
            scenes.Add(scene);
        }

        public void LoadContentAndCreateScenes(GraphicsDeviceManager graphics, ContentManager Content)
        {
            // Scene number 0
            Scene scene0 = new Scene();

            BackGround building = new BackGround();
            building.AddTexture(Content.Load<Texture2D>("protoBuilding.png"));
            building.position = new Vector2(480 / 2, 480);
            scene0.AddGameObject(building);

            FireMan fireMan;
            fireMan = new FireMan(graphics);
            fireMan.AddAnimation(new Animation(Content.Load<Texture2D>("FiremanFlyRightAnimation.png"), new Vector2(100, 100), 5));
            fireMan.AddAnimation(new Animation(Content.Load<Texture2D>("FiremanFlyLeftAnimation.png"), new Vector2(100, 100), 5));

            //fireMan.AddAnimation(new Animation(Content.Load<Texture2D>("MarkRight.png"), new Vector2(100, 100), 5));
            //fireMan.AddAnimation(new Animation(Content.Load<Texture2D>("MarkLeft.png"), new Vector2(100, 100), 5));

            fireMan.AddTexture(Content.Load<Texture2D>("FiremanAttackRight.png"));
            fireMan.AddTexture(Content.Load<Texture2D>("FiremanAttackLeft.png"));

            //fireMan.AddTexture(Content.Load<Texture2D>("MarkRightAttack.png"));
            //fireMan.AddTexture(Content.Load<Texture2D>("MarkLeftAttack.png"));

            WaterParticlesController particleController = new WaterParticlesController(40);
            particleController.AddTexture(Content.Load<Texture2D>("Drop.png"));
            fireMan.AddParticleController(particleController);
            scene0.AddGameObject(fireMan);

            Trampoline trampoline;
            trampoline = new Trampoline(graphics);
            trampoline.AddAnimation(new Animation(Content.Load<Texture2D>("TwoWithTrampolineAnimation.png"), new Vector2(150, 100), 10));
            trampoline.AddTexture(Content.Load<Texture2D>("TwoWithTrampoline1.png"));
            fireMan.trampoline = trampoline;
            scene0.AddGameObject(trampoline);


            this.AddScene(scene0);
            currentSceneNumber = 0;
        }
        /*
        public void RemoveScene(Scene scene)
        {
            scenes.Remove(scene);
        }
         * */
    }
}
