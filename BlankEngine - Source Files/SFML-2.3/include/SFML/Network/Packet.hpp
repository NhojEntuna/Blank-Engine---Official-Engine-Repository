�:    _               POINT   SHADOWS_OFF   _METALLICGLOSSMAP
   _NORMALMAP   _ALPHATEST_ON  !!GLSL
#ifdef VERTEX
uniform vec3 _WorldSpaceCameraPos;
uniform vec4 _WorldSpaceLightPos0;

uniform mat4 _Object2World;
uniform mat4 _World2Object;
uniform vec4 _MainTex_ST;
uniform vec4 _DetailAlbedoMap_ST;
uniform float _UVSec;
uniform mat4 _LightMatrix0;
attribute vec4 TANGENT;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec4 xlv_TEXCOORD2;
varying vec4 xlv_TEXCOORD2_1;
varying vec4 xlv_TEXCOORD2_2;
varying vec3 xlv_TEXCOORD5;
void main ()
{
  vec2 tmpvar_1;
  tmpvar_1 = gl_MultiTexCoord0.xy;
  vec2 tmpvar_2;
  tmpvar_2 = gl_MultiTexCoord1.xy;
  vec4 tmpvar_3;
  vec4 tmpvar_4;
  vec4 tmpvar_5;
  vec4 tmpvar_6;
  tmpvar_6 = (_Object2World * gl_Vertex);
  vec4 tmpvar_7;
  tmpvar_7 = (gl_ModelViewProjectionMatrix * gl_Vertex);
  vec4 texcoord_8;
  texcoord_8.xy = ((gl_MultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  vec2 tmpvar_9;
  if ((_UVSec == 0.0)) {
    tmpvar_9 = tmpvar_1;
  } else {
    tmpvar_9 = tmpvar_2;
  };
  texcoord_8.zw = ((tmpvar_9 * _DetailAlbedoMap_ST.xy) + _DetailAlbedoMap_ST.zw);
  vec4 v_10;
  v_10.x = _World2Object[0].x;
  v_10.y = _World2Object[1].x;
  v_10.z = _World2Object[2].x;
  v_10.w = _World2Object[3].x;
  vec4 v_11;
  v_11.x = _World2Object[0].y;
  v_11.y = _World2Object[1].y;
  v_11.z = _World2Object[2].y;
  v_11.w = _World2Object[3].y;
  vec4 v_12;
  v_12.x = _World2Object[0].z;
  v_12.y = _World2Object[1].z;
  v_12.z = _World2Object[2].z;
  v_12.w = _World2Object[3].z;
  vec3 tmpvar_13;
  tmpvar_13 = normalize(((
    (v_10.xyz * gl_Normal.x)
   + 
    (v_11.xyz * gl_Normal.y)
  ) + (v_12.xyz * gl_Normal.z)));
  mat3 tmpvar_14;
  tmpvar_14[0] = _Object2World[0].xyz;
  tmpvar_14[1] = _Object2World[1].xyz;
  tmpvar_14[2] = _Object2World[2].xyz;
  vec4 tmpvar_15;
  tmpvar_15.xyz = normalize((tmpvar_14 * TANGENT.xyz));
  tmpvar_15.w = TANGENT.w;
  vec3 tmpvar_16;
  vec3 tmpvar_17;
  tmpvar_16 = tmpvar_15.xyz;
  tmpvar_17 = (((tmpvar_13.yzx * tmpvar_15.zxy) - (tmpvar_13.zxy * tmpvar_15.yzx)) * TANGENT.www);
  vec3 tmpvar_18;
  vec3 tmpvar_19;
  vec3 tmpvar_20;
  tmpvar_18.x = tmpvar_16.x;
  tmpvar_18.y = tmpvar_17.x;
  tmpvar_18.z = tmpvar_13.x;
  tmpvar_19.x = tmpvar_16.y;
  tmpvar_19.y = tmpvar_17.y;
  tmpvar_19.z = tmpvar_13.y;
  tmpvar_20.x = tmpvar_16.z;
  tmpvar_20.y = tmpvar_17.z;
  tmpvar_20.z = tmpvar_13.z;
  vec3 v_21;
  v_21.x = tmpvar_18.x;
  v_21.y = tmpvar_19.x;
  v_21.z = tmpvar_20.x;
  tmpvar_3.xyz = v_21;
  vec3 v_22;
  v_22.x = tmpvar_18.y;
  v_22.y = tmpvar_19.y;
  v_22.z = tmpvar_20.y;
  tmpvar_4.xyz = v_22;
  vec3 v_23;
  v_23.x = tmpvar_18.z;
  v_23.y = tmpvar_19.z;
  v_23.z = tmpvar_20.z;
  tmpvar_5.xyz = v_23;
  vec3 tmpvar_24;
  tmpvar_24 = (_WorldSpaceLightPos0.xyz - (tmpvar_6.xyz * _WorldSpaceLightPos0.w));
  tmpvar_3.w = tmpvar_24.x;
  tmpvar_4.w = tmpvar_24.y;
  tmpvar_5.w = tmpvar_24.z;
  gl_Position = tmpvar_7;
  xlv_TEXCOORD0 = texcoord_8;
  xlv_TEXCOORD1 = (tmpvar_6.xyz - _WorldSpaceCameraPos);
  xlv_TEXCOORD2 = tmpvar_3;
  xlv_TEXCOORD2_1 = tmpvar_4;
  xlv_TEXCOORD2_2 = tmpvar_5;
  xlv_TEXCOORD5 = (_LightMatrix0 * (_Object2World * gl_Vertex)).xyz;
}


#endif
#ifdef FRAGMENT
uniform vec4 unity_ColorSpaceDielectricSpec;
uniform vec4 _LightColor0;
uniform vec4 unity_LightGammaCorrectionConsts;
uniform vec4 _Color;
uniform float _Cutoff;
uniform sampler2D _MainTex;
uniform sampler2D _BumpMap;
uniform float _BumpScale;
uniform sampler2D _MetallicGlossMap;
uniform sampler2D _LightTexture0;
varying vec4 xlv_TEXCOORD0;
varying vec3 xlv_TEXCOORD1;
varying vec4 xlv_TEXCOORD2;
varying vec4 xlv_TEXCOORD2_1;
varying vec4 xlv_TEXCOORD2_2;
varying vec3 xlv_TEXCOORD5;
void main ()
{
  vec3 tmpvar_1;
  vec3 tmpvar_2;
  vec3 tmpvar_3;
  tmpvar_1 = xlv_TEXCOORD2.xyz;
  tmpvar_2 = xlv_TEXCOORD2_1.xyz;
  tmpvar_3 = xlv_TEXCOORD2_2.xyz;
  mat3 tmpvar_4;
  tmpvar_4[0].x = tmpvar_1.x;
  tmpvar_4[0].y = tmpvar_2.x;
  tmpvar_4[0].z = tmpvar_3.x;
  tmpvar_4[1].x = tmpvar_1.y;
  tmpvar_4[1].y = tmpvar_2.y;
  tmpvar_4[1].z = tmpvar_3.y;
  tmpvar_4[2].x = tmpvar_1.z;
  tmpvar_4[2].y = tmpvar_2.z;
  tmpvar_4[2].z = tmpvar_3.z;
  float x_5;
  x_5 = ((texture2D (_MainTex, xlv_TEXCOORD0.xy).w * _Color.w) - _Cutoff);
  if ((x_5 < 0.0)) {
    discard;
  };
  vec3 normal_6;
  normal_6.xy = ((texture2D (_BumpMap, xlv_TEXCOORD0.xy).wy * 2.0) - 1.0);
  normal_6.xy = (normal_6.xy * _BumpScale);
  normal_6.z = sqrt((1.0 - clamp (
    dot (normal_6.xy, normal_6.xy)
  , 0.0, 1.0)));
  vec3 tmpvar_7;
  tmpvar_7 = normalize((normal_6 * tmpvar_4));
  vec2 tmpvar_8;
  tmpvar_8 = texture2D (_MetallicGlossMap, xlv_TEXCOORD0.xy).xw;
  vec3 tmpvar_9;
  tmpvar_9 = (_Color.xyz * texture2D (_MainTex, xlv_TEXCOORD0.xy).xyz);
  vec3 tmpvar_10;
  tmpvar_10 = mix (unity_ColorSpaceDielectricSpec.xyz, tmpvar_9, tmpvar_8.xxx);
  vec3 tmpvar_11;
  tmpvar_11.x = xlv_TEXCOORD2.w;
  tmpvar_11.y = xlv_TEXCOORD2_1.w;
  tmpvar_11.z = xlv_TEXCOORD2_2.w;
  vec3 tmpvar_12;
  tmpvar_12 = normalize(tmpvar_11);
  float tmpvar_13;
  tmpvar_13 = max (0.0, dot (tmpvar_7, tmpvar_12));
  vec3 tmpvar_14;
  tmpvar_14 = (_LightColor0.xyz * texture2D (_LightTexture0, vec2(dot (xlv_TEXCOORD5, xlv_TEXCOORD5))).w);
  vec3 viewDir_15;
  viewDir_15 = -(normalize(xlv_TEXCOORD1));
  float tmpvar_16;
  tmpvar_16 = (1.0 - tmpvar_8.y);
  vec3 tmpvar_17;
  tmpvar_17 = normalize((tmpvar_12 + viewDir_15));
  float tmpvar_18;
  tmpvar_18 = max (0.0, dot (tmpvar_7, viewDir_15));
  float tmpvar_19;
  tmpvar_19 = max (0.0, dot (tmpvar_12, tmpvar_17));
  float tmpvar_20;
  tmpvar_20 = ((tmpvar_16 * tmpvar_16) * unity_LightGammaCorrectionConsts.w);
  float tmpvar_21;
  float tmpvar_22;
  tmpvar_22 = (10.0 / log2((
    ((1.0 - tmpvar_16) * 0.968)
   + 0.03)));
  tmpvar_21 = (tmpvar_22 * tmpvar_22);
  float x_23;
  x_23 = (1.0 - tmpvar_13);
  float x_24;
  x_24 = (1.0 - tmpvar_18);
  float tmpvar_25;
  tmpvar_25 = (0.5 + ((
    (2.0 * tmpvar_19)
   * tmpvar_19) * tmpvar_16));
  float x_26;
  x_26 = (1.0 - tmpvar_19);
  vec4 tmpvar_27;
  tmpvar_27.w = 1.0;
  tmpvar_27.xyz = (((tmpvar_9 * 
    (unity_ColorSpaceDielectricSpec.w - (tmpvar_8.x * unity_ColorSpaceDielectricSpec.w))
  ) * (tmpvar_14 * 
    (((1.0 + (
      (tmpvar_25 - 1.0)
     * 
      ((((x_23 * x_23) * x_23) * x_23) * x_23)
    )) * (1.0 + (
      (tmpvar_25 - 1.0)
     * 
      ((((x_24 * x_24) * x_24) * x_24) * x_24)
    ))) * tmpvar_13)
  )) + ((
    max (0.0, (((
      (1.0/((((
        (tmpvar_13 * (1.0 - tmpvar_20))
       + tmpvar_20) * (
        (tmpvar_18 * (1.0 - tmpvar_20))
       + tmpvar_20)) + 0.0001)))
     * 
      (pow (max (0.0, dot (tmpvar_7, tmpvar_17)), tmpvar_21) * ((tmpvar_21 + 1.0) * unity_LightGammaCorrectionConsts.y))
    ) * tmpvar_13) * unity_LightGammaCorrectionConsts.x))
   * tmpvar_14) * (tmpvar_10 + 
    ((1.0 - tmpvar_10) * (((
      (x_26 * x_26)
     * x_26) * x_26) * x_26))
  )));
  vec4 xlat_varoutput_28;
  xlat_varoutput_28.xyz = tmpvar_27.xyz;
  xlat_varoutput_28.w = 1.0;
  gl_FragData[0] = xlat_varoutput_28;
}


#endif
�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           �:    <   	             WATER_REFLECTIVE   WATER_VERTEX_DISPLACEMENT_ON   WATER_EDGEBLEND_ON	  ps_4_0
eefiecedkibciakdnmdlobldnnniagmpcpghcjhiabaaaaaafealaaaaadaaaaaa
cmaaaaaaoeaaaaaabiabaaaaejfdeheolaaaaaaaagaaaaaaaiaaaaaajiaaaaaa
aaaaaaaaabaaaaaaadaaaaaaaaaaaaaaapaaaaaakeaaaaaaaaaaaaaaaaaaaaaa
adaaaaaaabaaaaaaapahaaaakeaaaaaaabaaaaaaaaaaaaaaadaaaaaaacaaaaaa
apapaaaakeaaaaaaacaaaaaaaaaaaaaaadaaaaaaadaaaaaaapapaaaakeaaaaaa
adaaaaaaaaaaaaaaadaaaaaaaeaaaaaaapapaaaakeaaaaaaaeaaaaaaaaaaaaaa
adaaaaaaafaaaaaaapalaaaafdfgfpfaepfdejfeejepeoaafeeffiedepepfcee
aaklklklepfdeheocmaaaaaaabaaaaaaaiaaaaaacaaaaaaaaaaaaaaaaaaaaaaa
adaaaaaaaaaaaaaaapaaaaaafdfgfpfegbhcghgfheaaklklfdeieefcdeakaaaa
eaaaaaaainacaaaafjaaaaaeegiocaaaaaaaaaaabjaaaaaafjaaaaaeegiocaaa
abaaaaaaaiaaaaaafkaaaaadaagabaaaaaaaaaaafkaaaaadaagabaaaabaaaaaa
fkaaaaadaagabaaaacaaaaaafkaaaaadaagabaaaadaaaaaafkaaaaadaagabaaa
aeaaaaaafibiaaaeaahabaaaaaaaaaaaffffaaaafibiaaaeaahabaaaabaaaaaa
ffffaaaafibiaaaeaahabaaaacaaaaaaffffaaaafibiaaaeaahabaaaadaaaaaa
ffffaaaafibiaaaeaahabaaaaeaaaaaaffffaaaagcbaaaadhcbabaaaabaaaaaa
gcbaaaadpcbabaaaacaaaaaagcbaaaadpcbabaaaadaaaaaagcbaaaadpcbabaaa
aeaaaaaagcbaaaadlcbabaaaafaaaaaagfaaaaadpccabaaaaaaaaaaagiaaaaac
agaaaaaaaoaaaaahdcaabaaaaaaaaaaaegbabaaaafaaaaaapgbpbaaaafaaaaaa
efaaaaajpcaabaaaaaaaaaaaegaabaaaaaaaaaaaeghobaaaabaaaaaaaagabaaa
acaaaaaaefaaaaajpcaabaaaabaaaaaaegbabaaaadaaaaaaeghobaaaaaaaaaaa
aagabaaaaaaaaaaaefaaaaajpcaabaaaacaaaaaaogbkbaaaadaaaaaaeghobaaa
aaaaaaaaaagabaaaaaaaaaaaaaaaaaahhcaabaaaabaaaaaapganbaaaabaaaaaa
pganbaaaacaaaaaaaaaaaaakhcaabaaaabaaaaaaegacbaaaabaaaaaaaceaaaaa
aaaaialpaaaaialpaaaaialpaaaaaaaadiaaaaaihcaabaaaabaaaaaaegacbaaa
abaaaaaaagiacaaaaaaaaaaaaoaaaaaadcaaaaamhcaabaaaabaaaaaaegacbaaa
abaaaaaaaceaaaaaaaaaiadpaaaaaaaaaaaaiadpaaaaaaaaegbcbaaaabaaaaaa
baaaaaahicaabaaaaaaaaaaaegacbaaaabaaaaaaegacbaaaabaaaaaaeeaaaaaf
icaabaaaaaaaaaaadkaabaaaaaaaaaaadiaaaaahhcaabaaaabaaaaaapgapbaaa
aaaaaaaaegacbaaaabaaaaaadiaaaaaidcaabaaaacaaaaaaigaabaaaabaaaaaa
fgifcaaaaaaaaaaaaoaaaaaadiaaaaakdcaabaaaacaaaaaaegaabaaaacaaaaaa
aceaaaaaaaaacaebaaaacaebaaaaaaaaaaaaaaaadgaaaaafecaabaaaacaaaaaa
abeaaaaaaaaaaaaaaaaaaaahhcaabaaaadaaaaaaegacbaaaacaaaaaaegbdbaaa
afaaaaaaaaaaaaahhcaabaaaacaaaaaaegacbaaaacaaaaaaegbdbaaaaeaaaaaa
aoaaaaahdcaabaaaacaaaaaaegaabaaaacaaaaaakgakbaaaacaaaaaaefaaaaaj
pcaabaaaacaaaaaaegaabaaaacaaaaaaeghobaaaadaaaaaaaagabaaaabaaaaaa
aoaaaaahdcaabaaaadaaaaaaegaabaaaadaaaaaakgakbaaaadaaaaaaefaaaaaj
pcaabaaaaeaaaaaaegaabaaaadaaaaaaeghobaaaacaaaaaaaagabaaaaeaaaaaa
efaaaaajpcaabaaaadaaaaaaegaabaaaadaaaaaaeghobaaaabaaaaaaaagabaaa
acaaaaaadcaaaaalicaabaaaaaaaaaaackiacaaaabaaaaaaahaaaaaaakaabaaa
aeaaaaaadkiacaaaabaaaaaaahaaaaaaaoaaaaakicaabaaaaaaaaaaaaceaaaaa
aaaaiadpaaaaiadpaaaaiadpaaaaiadpdkaabaaaaaaaaaaadbaaaaahicaabaaa
aaaaaaaadkaabaaaaaaaaaaackbabaaaaeaaaaaadhaaaaajhcaabaaaaaaaaaaa
pgapbaaaaaaaaaaaegacbaaaaaaaaaaaegacbaaaadaaaaaadiaaaaaiicaabaaa
aaaaaaaadkbabaaaacaaaaaadkiacaaaaaaaaaaaalaaaaaadcaaaaaopcaabaaa
adaaaaaapgapbaiaebaaaaaaaaaaaaaaaceaaaaajkjjbjdoipmcpfdmaknhcddm
aaaaaaaaegiocaaaaaaaaaaaajaaaaaaaaaaaaaihcaabaaaadaaaaaaegacbaia
ebaaaaaaaaaaaaaaegacbaaaadaaaaaadcaaaaajhcaabaaaaaaaaaaapgapbaaa
adaaaaaaegacbaaaadaaaaaaegacbaaaaaaaaaaaaaaaaaajhcaabaaaadaaaaaa
egacbaiaebaaaaaaacaaaaaaegiccaaaaaaaaaaaakaaaaaadcaaaaakhcaabaaa
acaaaaaapgipcaaaaaaaaaaaakaaaaaaegacbaaaadaaaaaaegacbaaaacaaaaaa
aaaaaaaihcaabaaaacaaaaaaegacbaiaebaaaaaaaaaaaaaaegacbaaaacaaaaaa
diaaaaaifcaabaaaadaaaaaaagacbaaaabaaaaaaagiacaaaaaaaaaaaapaaaaaa
dgaaaaafccaabaaaadaaaaaabkaabaaaabaaaaaabaaaaaahicaabaaaaaaaaaaa
egbcbaaaacaaaaaaegbcbaaaacaaaaaaeeaaaaaficaabaaaaaaaaaaadkaabaaa
aaaaaaaadiaaaaahhcaabaaaaeaaaaaapgapbaaaaaaaaaaaegbcbaaaacaaaaaa
dcaaaaakhcaabaaaafaaaaaaegbcbaaaacaaaaaapgapbaaaaaaaaaaaegiccaaa
aaaaaaaaanaaaaaabaaaaaaiicaabaaaaaaaaaaaegacbaiaebaaaaaaaeaaaaaa
egacbaaaadaaaaaadeaaaaahicaabaaaaaaaaaaadkaabaaaaaaaaaaaabeaaaaa
aaaaaaaaaaaaaaaiicaabaaaaaaaaaaadkaabaiaebaaaaaaaaaaaaaaabeaaaaa
aaaaiadpdeaaaaahicaabaaaaaaaaaaadkaabaaaaaaaaaaaabeaaaaaaaaaaaaa
cpaaaaaficaabaaaaaaaaaaadkaabaaaaaaaaaaadiaaaaaiicaabaaaaaaaaaaa
dkaabaaaaaaaaaaackiacaaaaaaaaaaaaoaaaaaabjaaaaaficaabaaaaaaaaaaa
dkaabaaaaaaaaaaaaaaaaaajicaabaaaabaaaaaadkiacaiaebaaaaaaaaaaaaaa
aoaaaaaaabeaaaaaaaaaiadpdccaaaakicaabaaaaaaaaaaadkaabaaaabaaaaaa
dkaabaaaaaaaaaaadkiacaaaaaaaaaaaaoaaaaaadcaaaaajhcaabaaaaaaaaaaa
pgapbaaaaaaaaaaaegacbaaaacaaaaaaegacbaaaaaaaaaaabaaaaaahicaabaaa
aaaaaaaaegacbaaaafaaaaaaegacbaaaafaaaaaaeeaaaaaficaabaaaaaaaaaaa
dkaabaaaaaaaaaaadiaaaaahhcaabaaaacaaaaaapgapbaaaaaaaaaaaegacbaaa
afaaaaaabaaaaaaiicaabaaaaaaaaaaaegacbaaaabaaaaaaegacbaiaebaaaaaa
acaaaaaadeaaaaahicaabaaaaaaaaaaadkaabaaaaaaaaaaaabeaaaaaaaaaaaaa
cpaaaaaficaabaaaaaaaaaaadkaabaaaaaaaaaaadiaaaaaiicaabaaaaaaaaaaa
dkaabaaaaaaaaaaaakiacaaaaaaaaaaaamaaaaaabjaaaaaficaabaaaaaaaaaaa
dkaabaaaaaaaaaaadcaaaaakhcaabaaaaaaaaaaapgapbaaaaaaaaaaaegiccaaa
aaaaaaaaaiaaaaaaegacbaaaaaaaaaaaaaaaaaahpcaabaaaabaaaaaaegbobaaa
adaaaaaaegbobaaaadaaaaaaefaaaaajpcaabaaaacaaaaaaegaabaaaabaaaaaa
eghobaaaaeaaaaaaaagabaaaadaaaaaaefaaaaajpcaabaaaabaaaaaaogakbaaa
abaaaaaaeghobaaaaeaaaaaaaagabaaaadaaaaaadcaaaaamhcaabaaaabaaaaaa
egacbaaaacaaaaaaegacbaaaabaaaaaaaceaaaaaaaaaaaloaaaaaaloaaaaaalo
aaaaaaaadiaaaaaihcaabaaaabaaaaaaegacbaaaabaaaaaaagiacaaaaaaaaaaa
biaaaaaaaoaaaaahdcaabaaaacaaaaaaegbabaaaaeaaaaaapgbpbaaaaeaaaaaa
efaaaaajpcaabaaaacaaaaaaegaabaaaacaaaaaaeghobaaaacaaaaaaaagabaaa
aeaaaaaadcaaaaalicaabaaaaaaaaaaackiacaaaabaaaaaaahaaaaaaakaabaaa
acaaaaaadkiacaaaabaaaaaaahaaaaaaaoaaaaakicaabaaaaaaaaaaaaceaaaaa
aaaaiadpaaaaiadpaaaaiadpaaaaiadpdkaabaaaaaaaaaaaaaaaaaaiicaabaaa
aaaaaaaadkaabaaaaaaaaaaadkbabaiaebaaaaaaaeaaaaaadicaaaaidcaabaaa
acaaaaaapgapbaaaaaaaaaaaegiacaaaaaaaaaaaalaaaaaaaaaaaaaiicaabaaa
aaaaaaaabkaabaiaebaaaaaaacaaaaaaabeaaaaaaaaaiadpdgaaaaaficcabaaa
aaaaaaaaakaabaaaacaaaaaaaacaaaajicaabaaaabaaaaaadkbabaaaacaaaaaa
bkiacaiaebaaaaaaaaaaaaaabiaaaaaaaaaaaaahicaabaaaaaaaaaaadkaabaaa
aaaaaaaadkaabaaaabaaaaaadcaaaaajhccabaaaaaaaaaaaegacbaaaabaaaaaa
pgapbaaaaaaaaaaaegacbaaaaaaaaaaadoaaaaab                          $Globals�  	      _SpecularColor                 �   
   _BaseColor                 �      _ReflectionColor                 �      _InvFadeParemeter     