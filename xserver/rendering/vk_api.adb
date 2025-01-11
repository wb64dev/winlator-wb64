
with Vulkan; use Vulkan;
with Vulkan.KHR.Swapchain; use Vulkan.KHR.Swapchain;

procedure Main is
   -- Vulkan instance
   Instance : Vk_Instance;

   -- Physical device
   Physical_Device : Vk_Physical_Device;

   -- Logical device
   Device : Vk_Device;

   -- Swapchain
   Swapchain : Vk_Swapchain_KHR;

   -- Image views
   Image_Views : array (0 .. 1) of Vk_Image_View;

   -- Render pass
   Render_Pass : Vk_Render_Pass;

   -- Framebuffer
   Framebuffer : Vk_Framebuffer;

   -- Command buffer
   Command_Buffer : Vk_Command_Buffer;

   -- Pipeline
   Pipeline : Vk_Pipeline;

   -- Vertex data
   Vertices : constant array (0 .. 2) of Vk_Vertex_Input_State := (
      (Binding => 0, Stride => 4 * Size_Of (Float), Input_Rate => Vertex_Input_Rate_Vertex),
      (Binding => 1, Stride => 4 * Size_Of (Float), Input_Rate => Vertex_Input_Rate_Instance)
   );
   -- Vertex buffer
   Vertex_Buffer : Vk_Buffer;

   -- Index buffer
   Index_Buffer : Vk_Buffer;
begin
   -- Initialize Vulkan library
   Vulkan.Initialize;

   -- Create Vulkan instance
   Instance := Create_Instance ("Vulkan Rendering", Application_Version => 1);

   -- Select physical device
   Physical_Device := Select_Physical_Device (Instance);

   -- Create logical device
   Device := Create_Device (Physical_Device, Queue_Create_Info => (
      Queue_Family_Index => 0,
      Queue_Priority => 1.0
   ));
   -- Create swapchain
   Swapchain := Create_Swapchain_KHR (
      Device,
      Surface => Create_Surface (Instance),
      Min_Image_Count => 2,
      Image_Format => Format_B8G8R8A8_Unorm,
      Image_Color_Space => Color_Space_SRGB_Nonlinear_KHR,
      Image_Extent => (Width => 800, Height => 600),
      Image_Array_Layers => 1,
      Image_Usage => Image_Usage_Color_ATTACHMENT_BIT
   );
   -- Create image views
   for I in Image_Views'Range loop
      Image_Views (I) := Create_Image_View (
         Device,
         Image => Get_Swapchain_Images_KHR (Swapchain)(I),
         View_Type => View_Type_2D,
         Format => Format_B8G8R8A8_Unorm
      );
   end loop;

   -- Create render pass
   Render_Pass := Create_Render_Pass (
      Device,
      Attachment_Descriptions => (
         (Format => Format_B8G8R8A8_Unorm, Load_Op => Load_Op_Clear, Store_Op => Store_Op_Store),
         (Format => Format_D32_Sfloat, Load_Op => Load_Op_Clear, Store_Op => Store_Op_Store)
      ),
      Subpass_Descriptions => (
         (Pipeline_Bind_Point => Pipeline_Bind_Point_Graphics, Color_Attachments => (
            (Attachment => 0, Layout => Layout_Attachment_Undefined)
         ))
      )
   );
   -- Create framebuffer
   Framebuffer := Create_Framebuffer (
      Device,
      Render_Pass => Render_Pass,
      Attachments => Image_Views,
      Width => 800,
      Height => 600,
      Layers => 1
   );
   -- Create command buffer
   Command_Buffer := Allocate_Command_Buffers (
      Device,
      Command_Buffer_Level => Command_Buffer_Level_Primary,
      Command_Buffer_Count => 1
   )(0);
   -- Create pipeline
   Pipeline := Create_Graphics_Pipelines (
      Device,
      Pipeline_Create_Info => (
         Stage_Create_Info => (
            (Shader Stage => Shader_Stage_Vertex_Bit, Module => Create_Shader_Module (
               Device,
               Code => Vertex_Shader_Code
            )),
            (Shader Stage => Shader_Stage_Fragment_Bit, Module => Create_Shader_Module (
               Device,
               Code => Fragment_Shader_Code
            ))
         ),
         Vertex_Input_State => Vertices,
         Input_Assembly_State => (
            Topology => Primitive_TOPOLOGY_TRIANGLE_LIST,
            Primitive_Restart_Enabled => False
         ),
         Viewport_State => (
            Viewports => (
               (X => 0.0, Y => 0.0, Width => 800.0, Height => 600.0, Min_Depth => 0.0, Max_Depth => 1.0)
            ),
            Sc
  
